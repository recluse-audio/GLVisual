uniform vec2  resolution;
uniform float audioSampleData[256];

void getAmplitudeForXPos (in float xPos, out float audioAmplitude)
{
    // Buffer size - 1
    float perfectSamplePosition = 255.0 * xPos / resolution.x;
    int leftSampleIndex = int (floor (perfectSamplePosition));
    int rightSampleIndex = int (ceil (perfectSamplePosition));
    audioAmplitude = mix (audioSampleData[leftSampleIndex], audioSampleData[rightSampleIndex], fract (perfectSamplePosition));
}

#define THICKNESS 0.2
void main()
{
    float y = gl_FragCoord.y / resolution.y;
    float amp = 0.0, a = 0.0;

    getAmplitudeForXPos (gl_FragCoord.x, amp);
    
    if(amp > 0.02)
    {
        //float amp1 = 0.5 - amp / 5; // 0.5 - 0.375  >>  0.5 + 0.375
       // float amp2 = 0.25 - amp / 5;
        //float amp3 = 0.75 - amp / 5;
        float a = abs(amp * 4);
    }


                                                     
    //float r = abs( THICKNESS / ( amp1 - y ) ); 
    //r = (r - abs (r * 0.2)) * a;

   // float g = abs( THICKNESS / ( amp2 - y ) ); 
    //g = (g - abs (g * 0.2)) * amp;

    //float b = abs( THICKNESS / ( amp3 - y ) );
    //b = (b - abs (b * 0.2)) * amp;


    gl_FragColor = vec4 (a, a, a, 1);
}
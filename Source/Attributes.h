/*
  ==============================================================================

    Attributes.h
    Created: 30 Sep 2021 9:58:11pm
    Author:  ryand

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
//==============================================================================
   // This class just manages the attributes that the shaders use.

struct Attributes
{
    explicit Attributes(OpenGLShaderProgram& shaderProgram)
    {
        position.reset(createAttribute(shaderProgram, "position"));
        normal.reset(createAttribute(shaderProgram, "normal"));
        sourceColour.reset(createAttribute(shaderProgram, "sourceColour"));
        textureCoordIn.reset(createAttribute(shaderProgram, "textureCoordIn"));
    }

    void enable()
    {
        //using namespace gl;
        glVertex3fv
        if (position.get() != nullptr)
        {
            glVertexAttribPointer(position->attributeID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
            glEnableVertexAttribArray(position->attributeID);
        }

        if (normal.get() != nullptr)
        {
            glVertexAttribPointer(normal->attributeID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(float) * 3));
            glEnableVertexAttribArray(normal->attributeID);
        }

        if (sourceColour.get() != nullptr)
        {
            glVertexAttribPointer(sourceColour->attributeID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(float) * 6));
            glEnableVertexAttribArray(sourceColour->attributeID);
        }

        if (textureCoordIn.get() != nullptr)
        {
            glVertexAttribPointer(textureCoordIn->attributeID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(float) * 10));
            glEnableVertexAttribArray(textureCoordIn->attributeID);
        }
    }

    void disable()
    {
        using namespace ::juce::gl;

        if (position.get() != nullptr)       glDisableVertexAttribArray(position->attributeID);
        if (normal.get() != nullptr)         glDisableVertexAttribArray(normal->attributeID);
        if (sourceColour.get() != nullptr)   glDisableVertexAttribArray(sourceColour->attributeID);
        if (textureCoordIn.get() != nullptr) glDisableVertexAttribArray(textureCoordIn->attributeID);
    }

    std::unique_ptr<juce::OpenGLShaderProgram::Attribute> position, normal, sourceColour, textureCoordIn;

private:
    static juce::OpenGLShaderProgram::Attribute* createAttribute(juce::OpenGLShaderProgram& shader,
        const juce::String& attributeName)
    {
        using namespace ::juce::gl;

        if (glGetAttribLocation(shader.getProgramID(), attributeName.toRawUTF8()) < 0)
            return nullptr;

        return new juce::OpenGLShaderProgram::Attribute(shader, attributeName.toRawUTF8());
    }
};
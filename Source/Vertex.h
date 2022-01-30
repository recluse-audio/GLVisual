/*
  ==============================================================================

    Vertex.h
    Created: 30 Sep 2021 9:58:39pm
    Author:  ryand

  ==============================================================================
*/

#pragma once
#include <juceHeader.h>

struct Vertex
{
    float position[3];
    float normal[3];
    float colour[4];
    float texCoord[2];
};
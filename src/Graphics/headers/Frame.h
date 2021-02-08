//
// Created on Feb 2, 2021.
//
#pragma once


#include "Image.h"
#include "RasterImg.h"
// Frames contain all the data for a single frame of an animatic
// including the image itself and any script-related information
// about it.
// Frames are containers for images, and Sequences are containers
// for frames (basically).
class Frame {
public:
    Frame();
    ~Frame();

public:
    Image* m_frameImage;
    const char* m_frameName;
    const char* m_frameDesc;
    // Information about position in the sequence
    bool m_isNewScene;
    int m_sceneNum;
    int m_shotNum;
};
//
// Created on Feb 2, 2021.
//

#include "headers/Frame.h"

Frame::Frame() {
    m_frameImage = new Image();
    // Todo: Make the name of the frame from the scene/shot numbers
    m_frameName = "Frame";
    m_frameDesc = "No Description";
    
    m_isNewScene = false;
    m_sceneNum = 0; // Fix this later
    m_shotNum = 0; //Fix this too
}
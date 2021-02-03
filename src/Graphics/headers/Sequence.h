//
// Created on Feb 2, 2021.
//
#pragma once

#include "Frame.h"

#include <vector>

// Sequences contain the frames of the animatic.
class Sequence {
public:
    Sequence();
    ~Sequence();

public:
// Stored as pointers to improve performance of moving/adding frames
// Possible optimization from storing the frames themselves is only
// useful for exports, and is largely negligible.
    std::vector<Frame*> m_frameSequence;
};
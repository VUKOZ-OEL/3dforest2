/*
    Copyright 2020 VUKOZ

    This file is part of 3D Forest.

    3D Forest is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    3D Forest is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with 3D Forest.  If not, see <https://www.gnu.org/licenses/>.
*/

/** @file SegmentationL1TaskMedian.hpp */

#ifndef SEGMENTATION_L1_TASK_MEDIAN_HPP
#define SEGMENTATION_L1_TASK_MEDIAN_HPP

#include <Editor.hpp>
#include <SegmentationL1TaskInterface.hpp>

/** Segmentation L1 Task Median. */
class SegmentationL1TaskMedian : public SegmentationL1TaskInterface
{
public:
    virtual void initialize(SegmentationL1Context *context);
    virtual void next();

private:
    SegmentationL1Context *context_;
    size_t index_;
    size_t iterations_;
    size_t iteration_;
    double radius_;

    void step();
    void setupSearchRadius();
};

#endif /* SEGMENTATION_L1_TASK_MEDIAN_HPP */

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

/** @file SegmentationThread.hpp */

#ifndef SEGMENTATION_THREAD_HPP
#define SEGMENTATION_THREAD_HPP

#include <Query.hpp>
#include <SegmentationPca.hpp>
#include <Thread.hpp>
#include <Vector3.hpp>
#include <Voxels.hpp>

class Editor;

/** Segmentation Thread. */
class SegmentationThread : public Thread
{
public:
    SegmentationThread(Editor *editor);
    virtual ~SegmentationThread();

    void clear();

    void start(int voxelSize, int thresholdPercent);
    int progressPercent() const { return progressPercent_; }

    virtual bool compute();

    const Editor *editor() const { return editor_; }

protected:
    /** Segmentation Thread State. */
    enum State
    {
        STATE_VOXEL_SIZE,
        STATE_VOXEL_NORMALIZE,
        STATE_THRESHOLD,
        STATE_PREPARE_ELEMENTS,
        STATE_CREATE_ELEMENTS,
        STATE_MERGE_CLUSTERS,
        STATE_FINISHED,
    };

    Editor *editor_;
    Query query_;

    State state_;
    bool stateInitialized_;
    bool layersCreated_;
    uint64_t progressMax_;
    uint64_t progressValue_;
    int progressPercent_;

    int voxelSize_;
    int thresholdPercent_;

    Voxels voxels_;
    SegmentationPca pca_;
    float thresholdIntensity_;

    void setState(State state);
    void updateProgressPercent();

    void computeInitializeLayers();

    bool computeVoxelSize();
    bool computeNormalize();
    bool computeThreshold();
    bool computePrepareElements();
    bool computeCreateElements();
    bool computeMergeClusters();
};

#endif /* SEGMENTATION_THREAD_HPP */

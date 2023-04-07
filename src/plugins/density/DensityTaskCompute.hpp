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

/** @file DensityTaskCompute.hpp */

#ifndef DENSITY_TASK_COMPUTE_HPP
#define DENSITY_TASK_COMPUTE_HPP

#include <DensityTaskInterface.hpp>

/** Density Task Compute. */
class DensityTaskCompute : public DensityTaskInterface
{
public:
    virtual void initialize(DensityContext *context);
    virtual void next();

private:
    DensityContext *context_;
    void step();
};

#endif /* DENSITY_TASK_COMPUTE_HPP */

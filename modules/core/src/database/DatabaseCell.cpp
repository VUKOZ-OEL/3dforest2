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

/**
    @file DatabaseCell.cpp
*/

#include <DatabaseCell.hpp>

DatabaseCell::DatabaseCell()
    : dataSetId(0), cellId(0), loaded(false), modified(false)
{
}

DatabaseCell::~DatabaseCell()
{
}

DatabaseCell::View::View() : renderStep(1), renderStepCount(1)
{
}

DatabaseCell::View::~View()
{
}

void DatabaseCell::View::resetFrame()
{
    renderStep = 1;
}

void DatabaseCell::View::nextFrame()
{
    renderStep++;
}

bool DatabaseCell::View::isStarted() const
{
    return renderStep == 1;
}

bool DatabaseCell::View::isFinished() const
{
    return renderStep > renderStepCount;
}

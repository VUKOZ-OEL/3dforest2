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
    @file Forest3dPluginToolExample.cpp
*/

#include <Forest3dPluginToolExample.hpp>
#include <Forest3dPluginToolExampleWindow.hpp>

Forest3dPluginToolExample::Forest3dPluginToolExample() : window_(nullptr)
{
}

Forest3dPluginToolExample::~Forest3dPluginToolExample()
{
}

void Forest3dPluginToolExample::show(QWidget *parent, Forest3dEditor *editor)
{
    if (!window_)
    {
        window_ = new Forest3dPluginToolExampleWindow(parent, editor);
    }

    window_->show();
    window_->raise();
    window_->activateWindow();
}

QString Forest3dPluginToolExample::name() const
{
    return tr("Example");
}

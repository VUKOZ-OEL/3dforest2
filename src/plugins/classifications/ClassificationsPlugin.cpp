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

/** @file ClassificationsPlugin.cpp */

// Include 3D Forest.
#include <ClassificationsPlugin.hpp>
#include <ClassificationsWindow.hpp>
#include <MainWindow.hpp>
#include <ThemeIcon.hpp>

// Include local.
#define LOG_MODULE_NAME "ClassificationsPlugin"
#include <Log.hpp>

#define ICON(name) (ThemeIcon(":/classifications/", name))

ClassificationsPlugin::ClassificationsPlugin()
    : mainWindow_(nullptr),
      pluginWindow_(nullptr)
{
}

void ClassificationsPlugin::initialize(MainWindow *mainWindow)
{
    mainWindow_ = mainWindow;

    mainWindow_->createAction(nullptr,
                              "View",
                              "View",
                              tr("Classifications"),
                              tr("Show classifications explorer"),
                              ICON("classifications"),
                              this,
                              SLOT(slotPlugin()));
}

void ClassificationsPlugin::slotPlugin()
{
    if (!mainWindow_)
    {
        return;
    }

    if (!pluginWindow_)
    {
        pluginWindow_ = new ClassificationsWindow(mainWindow_);
    }

    pluginWindow_->show();
    pluginWindow_->raise();
    pluginWindow_->activateWindow();
}

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

/** @file ClassificationFilterWindow.hpp */

#ifndef CLASSIFICATION_FILTER_WINDOW_HPP
#define CLASSIFICATION_FILTER_WINDOW_HPP

// Include 3D Forest.
class MainWindow;
class ClassificationFilterWidget;

// Include Qt.
#include <QDockWidget>
class QCloseEvent;

/** Classification Filter Window. */
class ClassificationFilterWindow : public QDockWidget
{
    Q_OBJECT

public:
    ClassificationFilterWindow(MainWindow *mainWindow);

protected:
    ClassificationFilterWidget *widget_;

    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
};

#endif /* CLASSIFICATION_FILTER_WINDOW_HPP */

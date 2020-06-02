/* DUKTO - A simple, fast and multi-platform file transfer tool for LAN users
 * Copyright (C) 2011 Emanuele Colombo
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <QApplication>
#include "qmlapplicationviewer.h"

#include "guibehind.h"
#include "duktowindow.h"
#include "qtsingleapplication.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_LINUX)
    // qt5 removed setGraphicsSystem
//    QApplication::setGraphicsSystem("raster");
    qDebug("os: linux");
#elif defined (Q_OS_WIN)
    qDebug("os: windows");
    qputenv("QML_ENABLE_TEXT_IMAGE_CACHE", "true");
#endif

    // Check for single running instance
    QtSingleApplication app(argc, argv);
    if (app.isRunning()) {
        app.sendMessage("FOREGROUND");
        return 0;
    }

    qDebug("setActivationWindow");
    DuktoWindow viewer;
    app.setActivationWindow(&viewer, true);
    GuiBehind gb(&viewer);

    qDebug("showExpanded");
    viewer.showExpanded();

    qDebug("installEventFilter");
    app.installEventFilter(&gb);

    return app.exec();
}

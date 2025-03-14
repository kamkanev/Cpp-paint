/*
 * SPDX-FileCopyrightText: 2013-2023 Mattia Basaglia
 * SPDX-License-Identifier: LGPL-3.0-or-later
 */

#ifndef QT_COLOR_WIDGETS_GLOBAL_H
#define QT_COLOR_WIDGETS_GLOBAL_H

#include <QtCore/QtGlobal>

#if defined(QTCOLORWIDGETS_STATICALLY_LINKED)
#    define QCP_EXPORT
#elif defined(QTCOLORWIDGETS_LIBRARY)
#    define QCP_EXPORT Q_DECL_EXPORT
#else
#    define QCP_EXPORT Q_DECL_IMPORT
#endif

#endif // QT_COLOR_WIDGETS_GLOBAL_H

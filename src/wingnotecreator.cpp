/*==============================================================================
** Copyright (C) 2024-2027 WingSummer
**
** This program is free software: you can redistribute it and/or modify it under
** the terms of the GNU Affero General Public License as published by the Free
** Software Foundation, version 3.
**
** This program is distributed in the hope that it will be useful, but WITHOUT
** ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
** FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more
** details.
**
** You should have received a copy of the GNU Affero General Public License
** along with this program. If not, see <https://www.gnu.org/licenses/>.
** =============================================================================
*/

#include "wingnotecreator.h"

#include "noteeditorwidget.h"

QIcon WingNoteCreator::icon() const {
    return QIcon(QStringLiteral("://img/notepad.png"));
}

QString WingNoteCreator::name() const { return tr("WingHexNote"); }

QString WingNoteCreator::id() const { return QStringLiteral("WingHexNote"); }

WingHex::WingEditorViewWidget *WingNoteCreator::create(QWidget *parent) const {
    return new NoteEditorWidget(parent);
}

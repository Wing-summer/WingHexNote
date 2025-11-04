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
#include "winghexnote.h"

#include "wingnotecreator.h"

WingHexNote::WingHexNote() {}

bool WingHexNote::init(const std::unique_ptr<QSettings> &set) {
    Q_UNUSED(set);
    return true;
}

void WingHexNote::unload(std::unique_ptr<QSettings> &set) { Q_UNUSED(set); }

const QString WingHexNote::pluginName() const { return tr("WingHexNote"); }

const QString WingHexNote::pluginComment() const {
    return tr("A note plugin for WingHexExplorer2");
}

QString WingHexNote::retranslate(const QString &str) {
    return QApplication::tr(str.toLatin1());
}

QList<QSharedPointer<WingHex::WingEditorViewWidget::Creator>>
WingHexNote::registeredEditorViewWidgets() const {
    return {QSharedPointer<WingNoteCreator>::create()};
}

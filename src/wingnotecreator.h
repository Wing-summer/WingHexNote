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

#ifndef WINGNOTECREATOR_H
#define WINGNOTECREATOR_H

#include "WingPlugin/wingeditorviewwidget.h"

#include <QApplication>

class WingNoteCreator : public WingHex::WingEditorViewWidget::Creator {
    Q_DECLARE_TR_FUNCTIONS(WingNoteCreator)

public:
    WingNoteCreator() = default;

public:
    virtual QIcon icon() const override;

    virtual QString name() const override;

    virtual QString id() const override;

public:
    virtual WingHex::WingEditorViewWidget *
    create(QWidget *parent) const override;
};

#endif // WINGNOTECREATOR_H

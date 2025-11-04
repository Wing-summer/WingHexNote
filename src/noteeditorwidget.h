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

#ifndef NOTEEDITORWIDGET_H
#define NOTEEDITORWIDGET_H

#include "WingPlugin/wingeditorviewwidget.h"

#include <QPlainTextEdit>

class NoteEditorWidget : public WingHex::WingEditorViewWidget {
    Q_OBJECT

public:
    NoteEditorWidget(QWidget *parent = nullptr);

public:
    virtual WingHex::WingEditorViewWidget *clone() override;

public slots:
    virtual void loadState(const QByteArray &state) override;

    virtual bool hasUnsavedState() override;

    virtual QByteArray saveState() override;

    virtual void onWorkSpaceNotify(bool isWorkSpace) override;

    virtual void setSaved() override;

private slots:
    void updateCharCount();

private:
    QPlainTextEdit *_edit = nullptr;
    QLabel *_status = nullptr;
};

#endif // NOTEEDITORWIDGET_H

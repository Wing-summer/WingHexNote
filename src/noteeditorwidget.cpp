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

#include "noteeditorwidget.h"

#include <QLabel>
#include <QVBoxLayout>

NoteEditorWidget::NoteEditorWidget(QWidget *parent)
    : WingHex::WingEditorViewWidget(parent) {
    auto layout = new QVBoxLayout(this);
    auto lbl = new QLabel(tr("WingHexNote"), this);
    lbl->setAlignment(Qt::AlignCenter);
    layout->addWidget(lbl);
    _edit = new QPlainTextEdit(this);
    connect(_edit->document(), &QTextDocument::modificationChanged, this,
            &NoteEditorWidget::savedStateChanged);
    layout->addWidget(_edit);
    _status = new QLabel(this);
    _status->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    layout->addWidget(_status);
    connect(_edit, &QPlainTextEdit::textChanged, this,
            &NoteEditorWidget::updateCharCount);
    updateCharCount();
}

WingHex::WingEditorViewWidget *NoteEditorWidget::clone() {
    auto editor = new NoteEditorWidget;
    editor->_edit->setDocument(this->_edit->document());
    return editor;
}

void NoteEditorWidget::loadState(const QByteArray &state) {
    _edit->setPlainText(QString::fromUtf8(state));
}

bool NoteEditorWidget::hasUnsavedState() {
    if (_edit->isEnabled()) {
        return _edit->document()->isModified();
    }
    return false;
}

QByteArray NoteEditorWidget::saveState() {
    auto txt = _edit->toPlainText();
    return txt.toUtf8();
}

void NoteEditorWidget::onWorkSpaceNotify(bool isWorkSpace) {
    _edit->setEnabled(isWorkSpace);
}

void NoteEditorWidget::setSaved() { _edit->document()->setModified(false); }

void NoteEditorWidget::updateCharCount() {
    _status->setText(tr("Length: %1").arg(_edit->document()->characterCount()));
}

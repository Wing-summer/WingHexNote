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

#ifndef WINGHEXNOTE_H
#define WINGHEXNOTE_H

#include "WingPlugin/iwingplugin.h"

class WingHexNote : public WingHex::IWingPlugin {
    Q_OBJECT

    Q_PLUGIN_METADATA(IID "com.wingsummer.iwingplugin" FILE "WingHexNote.json")
    Q_INTERFACES(WingHex::IWingPlugin)
public:
    explicit WingHexNote();

    // IWingPluginCoreBase interface
public:
    virtual bool init(const std::unique_ptr<QSettings> &set) override;
    virtual void unload(std::unique_ptr<QSettings> &set) override;

    // IWingPluginBase interface
public:
    virtual const QString pluginName() const override;
    virtual const QString pluginComment() const override;

    virtual QString retranslate(const QString &str) override;

public:
    virtual QList<QSharedPointer<WingHex::WingEditorViewWidget::Creator>>
    registeredEditorViewWidgets() const override;
};

#endif // WINGHEXNOTE_H

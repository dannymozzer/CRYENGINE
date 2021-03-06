// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <QAbstractItemModel>

namespace ACE
{
namespace Impl
{
namespace Wwise
{
class CItem;

class CItemModel final : public QAbstractItemModel
{
public:

	enum class EColumns
	{
		Notification,
		Connected,
		Localized,
		Name,
		Count,
	};

	explicit CItemModel(CItem const& rootItem, QObject* const pParent);

	CItemModel() = delete;

	void Reset();

protected:

	// QAbstractItemModel
	virtual int             rowCount(QModelIndex const& parent) const override;
	virtual int             columnCount(QModelIndex const& parent) const override;
	virtual QVariant        data(QModelIndex const& index, int role) const override;
	virtual QVariant        headerData(int section, Qt::Orientation orientation, int role) const override;
	virtual Qt::ItemFlags   flags(QModelIndex const& index) const override;
	virtual QModelIndex     index(int row, int column, QModelIndex const& parent = QModelIndex()) const override;
	virtual QModelIndex     parent(QModelIndex const& index) const override;
	virtual bool            canDropMimeData(QMimeData const* pData, Qt::DropAction action, int row, int column, QModelIndex const& parent) const override;
	virtual bool            dropMimeData(QMimeData const* pData, Qt::DropAction action, int row, int column, QModelIndex const& parent) override;
	virtual Qt::DropActions supportedDragActions() const override;
	virtual QStringList     mimeTypes() const override;
	virtual QMimeData*      mimeData(QModelIndexList const& indexes) const override;
	// ~QAbstractItemModel

private:

	CItem*      ItemFromIndex(QModelIndex const& index) const;
	QModelIndex IndexFromItem(CItem const* const pItem) const;

	CItem const& m_rootItem;
};
} // namespace Wwise
} // namespace Impl
} // namespace ACE


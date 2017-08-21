#include "MyTableModel.h"
#include <QFont>
#include <QBrush>

MyTableModel::MyTableModel(GeneRepository& r) : repo{ r }
{
}


MyTableModel::~MyTableModel()
{
}

int MyTableModel::rowCount(const QModelIndex & index) const
{
	return this->repo.getSize();
}

int MyTableModel::columnCount(const QModelIndex & index) const
{
	return 3;
}

QVariant MyTableModel::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int col = index.column();

	std::vector<Gene> genes = this->repo.getGenes();
	
	if (row < 0 || row >= genes.size())
		return QVariant{};
	
	Gene currentGene = genes[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (col)
		{
		case 0:
			return QString::fromStdString(currentGene.getOrganismName());
		case 1:
			return QString::fromStdString(currentGene.getName());
		case 2:
			return QString::fromStdString(currentGene.getGeneFunction());
		}
	}

	if (role == Qt::FontRole)
	{
		QFont f{ "Times", 15, 10 };
		return f;
	}

	if (row % 2 == 0)
	{
		if (role == Qt::BackgroundRole)
		{
			QBrush brush{ QColor{ Qt::green } };
			return brush;
		}
	}

	return QVariant();
}

bool MyTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;

	// set the new data to the gene
	int geneIndex = index.row();

	std::vector<Gene> genes = this->repo.getGenes();
	Gene currentGene = genes[geneIndex];
	switch (index.column())
	{
	case 0:
		currentGene.setOrganismName(value.toString().toStdString());
		break;
	case 1:
		currentGene.setName(value.toString().toStdString());
		break;
	case 2:
		currentGene.setFunction(value.toString().toStdString());
	}
	this->repo.updateGene(geneIndex, currentGene);

	// emit the dataChanged signal
	emit dataChanged(index, index);

	return true;
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex & index) const
{
	return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}

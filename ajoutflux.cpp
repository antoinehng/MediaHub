#include "ajoutflux.h"
#include "configin.h"
#include "configout.h"

AjoutFlux::AjoutFlux(QWidget *parent) : QWidget(parent)
{
    QWidget *fenAjout = new QWidget(this);
    QGridLayout *glAjout = new QGridLayout;
    fenAjout->setFixedSize(250, 150);
    fenAjout->setWindowTitle("Assistant I/O");

    glAjout->setSpacing(4);
    fenAjout->setLayout(glAjout);

    m_labelIO = new QLabel("Que souhaitez-vous configurer?");
    m_boutonIN = new QPushButton("Entrée");
    m_boutonOUT = new QPushButton("Sortie");
    m_boutonQuit = new QPushButton("Annuler");

    glAjout->addWidget(m_labelIO,0,0,1,2);
    glAjout->addWidget(m_boutonIN,1,0);
    glAjout->addWidget(m_boutonOUT,1,1);
    glAjout->addWidget(m_boutonQuit,2,1);

    connect(m_boutonIN, SIGNAL(clicked()), this, SLOT(Entree()));
    connect(m_boutonOUT, SIGNAL(clicked()), this, SLOT(Sortie()));
    connect(m_boutonQuit, SIGNAL(clicked()), this, SLOT(Annuler()));
}


void AjoutFlux::Annuler()
{
    this->close();
}

void AjoutFlux::Entree()
{
    configIN *FenetreConfigIN = new configIN;
    FenetreConfigIN->show();
    this->close();
}

void AjoutFlux::Sortie()
{
    configOUT *FenetreConfigOUT = new configOUT;
    FenetreConfigOUT->show();
    this->close();
}

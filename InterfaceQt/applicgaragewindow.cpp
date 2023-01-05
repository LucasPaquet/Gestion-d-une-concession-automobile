#include "applicgaragewindow.h"
#include "ui_applicgaragewindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <sstream>

#include "Garage.h"

using namespace std;

#define REPERTOIRE_IMAGES "images/"

ApplicGarageWindow::ApplicGarageWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::ApplicGarageWindow)
{

    ui->setupUi(this);

    // Configuration de la table des options (projet en cours)
    ui->tableWidgetOptions->setColumnCount(3);
    ui->tableWidgetOptions->setRowCount(5);
    for (int i=0 ; i<5 ; i++) ui->tableWidgetOptions->setRowHeight(i,10);
    QStringList labelsTableOptions;
    labelsTableOptions << "Code" << "Prix" << "Intitulé";
    ui->tableWidgetOptions->setHorizontalHeaderLabels(labelsTableOptions);
    ui->tableWidgetOptions->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetOptions->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetOptions->horizontalHeader()->setVisible(true);
    ui->tableWidgetOptions->horizontalHeader()->setDefaultSectionSize(60);
    ui->tableWidgetOptions->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetOptions->verticalHeader()->setVisible(false);
    ui->tableWidgetOptions->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des employes (Personnel Garage)
    ui->tableWidgetEmployes->setColumnCount(4);
    ui->tableWidgetEmployes->setRowCount(0);
    QStringList labelsTableEmployes;
    labelsTableEmployes << "Numéro" << "Nom" << "Prénom" << "Fonction";
    ui->tableWidgetEmployes->setHorizontalHeaderLabels(labelsTableEmployes);
    ui->tableWidgetEmployes->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetEmployes->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetEmployes->horizontalHeader()->setVisible(true);
    ui->tableWidgetEmployes->horizontalHeader()->setDefaultSectionSize(80);
    ui->tableWidgetEmployes->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetEmployes->verticalHeader()->setVisible(false);
    ui->tableWidgetEmployes->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des clients
    ui->tableWidgetClients->setColumnCount(4);
    ui->tableWidgetClients->setRowCount(0);
    QStringList labelsTableClients;
    labelsTableClients << "Numéro" << "Nom" << "Prénom" << "GSM";
    ui->tableWidgetClients->setHorizontalHeaderLabels(labelsTableClients);
    ui->tableWidgetClients->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetClients->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetClients->horizontalHeader()->setVisible(true);
    ui->tableWidgetClients->horizontalHeader()->setDefaultSectionSize(80);
    ui->tableWidgetClients->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetClients->verticalHeader()->setVisible(false);
    ui->tableWidgetClients->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des contrats
    ui->tableWidgetContrats->setColumnCount(4);
    ui->tableWidgetContrats->setRowCount(0);
    QStringList labelsTableContrats;
    labelsTableContrats << "Numéro" << "Vendeur" << "Client" << "Voiture";
    ui->tableWidgetContrats->setHorizontalHeaderLabels(labelsTableContrats);
    ui->tableWidgetContrats->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetContrats->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetContrats->horizontalHeader()->setVisible(true);
    ui->tableWidgetContrats->horizontalHeader()->setDefaultSectionSize(80);
    ui->tableWidgetContrats->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetContrats->verticalHeader()->setVisible(false);
    ui->tableWidgetContrats->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Importation des modeles (étape 10)
    // TO DO
    Garage::getInstance().importeModeles("Modeles.csv");
    for (int i = 0; i < Garage::getInstance().getSizeModele(); i++)
    {
        cout << Garage::getInstance().getModele(i) << endl;
        ajouteModeleDisponible(Garage::getInstance().getModele(i).getNom(),Garage::getInstance().getModele(i).getPrixDeBase());
    }
    // Importation des options (étape 10)
    // TO DO
    Garage::getInstance().importeOptions("Options.csv");
    for (int i = 0; i < Garage::getInstance().getSizeOption(); i++)
    {
        ajouteOptionDisponible(Garage::getInstance().getOption(i).getIntitule().c_str(),Garage::getInstance().getOption(i).getPrix());
    }


    // Ouverture (et/ou creation) du fichier Garage.data (étape 12)
    // TO DO


    for (int i=0; i < Garage::getInstance().getSizeEmploye(); i++)// pour que ADMIN soit afficher
    {
        ajouteTupleTableEmployes(Garage::getInstance().getEmploye(i).Tuple());
    }
    setRole(0);  // acces a tout pour l'instant

    //******* EXEMPLES (A SUPPRIMER) *******************************************
    // setTableOption(1,"XY08","Toit ouvrant",850.0);
    // setModele("Peugeot 308",120,1,22300.0,"308.jpg");
    // ajouteTupleTableEmployes("2;Wagner;Jean-Marc;Vendeur");
    // ajouteTupleTableClients("8;Leonard;Anne;0475/47.25.36");
    // ajouteTupleTableContrats("3;Wagner Jean-Marc;Quettier Patrick;508_ProjetQuettier");
    //**************************************************************************
}

ApplicGarageWindow::~ApplicGarageWindow()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Titre de la fenêtre (ne pas modifier) //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setTitre(string titre)
{
    this->setWindowTitle(titre.c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Gestion des roles (ne pas modifier) ////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setRole(int val)
{
    // val = 0 --> personne n'est loggé
    // val = 1 --> un administratif est loggé
    // val = 2 --> un vendeur loggé
    // val = 3 --> on a accès à tout

    if (val == 0)
    {
        ui->actionLogin->setEnabled(true);
        ui->actionLogout->setEnabled(false);
        ui->actionReset_Mot_de_passe->setEnabled(false);
        ui->menuEmployes->setEnabled(false);
        ui->menuClients->setEnabled(false);
        ui->menuVoiture->setEnabled(false);
        ui->comboBoxModelesDisponibles->setEnabled(false);
        ui->comboBoxOptionsDisponibles->setEnabled(false);
        ui->pushButtonOuvrirProjet->setEnabled(false);
        ui->pushButtonNouveauProjet->setEnabled(false);
        ui->pushButtonReduction->setEnabled(false);
        ui->pushButtonEnregistrerProjet->setEnabled(false);
        ui->pushButtonAjouterOption->setEnabled(false);
        ui->pushButtonSupprimerOption->setEnabled(false);
        ui->pushButtonChoisirModele->setEnabled(false);
        ui->pushButtonVisualiserVoiture->setEnabled(false);
        ui->pushButtonNouveauContrat->setEnabled(false);
        ui->pushButtonSupprimerContrat->setEnabled(false);
    }

    if (val == 1)
    {
        ui->actionLogin->setEnabled(false);
        ui->actionLogout->setEnabled(true);
        ui->actionReset_Mot_de_passe->setEnabled(true);
        ui->menuEmployes->setEnabled(true);
        ui->menuClients->setEnabled(false);
        ui->menuVoiture->setEnabled(false);
        ui->comboBoxModelesDisponibles->setEnabled(false);
        ui->comboBoxOptionsDisponibles->setEnabled(false);
        ui->pushButtonOuvrirProjet->setEnabled(false);
        ui->pushButtonNouveauProjet->setEnabled(false);
        ui->pushButtonReduction->setEnabled(false);
        ui->pushButtonEnregistrerProjet->setEnabled(false);
        ui->pushButtonAjouterOption->setEnabled(false);
        ui->pushButtonSupprimerOption->setEnabled(false);
        ui->pushButtonChoisirModele->setEnabled(false);
        ui->pushButtonVisualiserVoiture->setEnabled(true);
        ui->pushButtonNouveauContrat->setEnabled(false);
        ui->pushButtonSupprimerContrat->setEnabled(true);
    }

    if (val == 2)
    {
        ui->actionLogin->setEnabled(false);
        ui->actionLogout->setEnabled(true);
        ui->actionReset_Mot_de_passe->setEnabled(true);
        ui->menuEmployes->setEnabled(false);
        ui->menuClients->setEnabled(true);
        ui->menuVoiture->setEnabled(true);
        ui->comboBoxModelesDisponibles->setEnabled(true);
        ui->comboBoxOptionsDisponibles->setEnabled(true);
        ui->pushButtonOuvrirProjet->setEnabled(true);
        ui->pushButtonNouveauProjet->setEnabled(true);
        ui->pushButtonReduction->setEnabled(true);
        ui->pushButtonEnregistrerProjet->setEnabled(true);
        ui->pushButtonAjouterOption->setEnabled(true);
        ui->pushButtonSupprimerOption->setEnabled(true);
        ui->pushButtonChoisirModele->setEnabled(true);
        ui->pushButtonVisualiserVoiture->setEnabled(true);
        ui->pushButtonNouveauContrat->setEnabled(true);
        ui->pushButtonSupprimerContrat->setEnabled(true);
    }

    if (val == 3)
    {
        ui->actionLogin->setEnabled(true);
        ui->actionLogout->setEnabled(true);
        ui->actionReset_Mot_de_passe->setEnabled(true);
        ui->menuEmployes->setEnabled(true);
        ui->menuClients->setEnabled(true);
        ui->menuVoiture->setEnabled(true);
        ui->comboBoxModelesDisponibles->setEnabled(true);
        ui->comboBoxOptionsDisponibles->setEnabled(true);
        ui->pushButtonOuvrirProjet->setEnabled(true);
        ui->pushButtonNouveauProjet->setEnabled(true);
        ui->pushButtonReduction->setEnabled(true);
        ui->pushButtonEnregistrerProjet->setEnabled(true);
        ui->pushButtonAjouterOption->setEnabled(true);
        ui->pushButtonSupprimerOption->setEnabled(true);
        ui->pushButtonChoisirModele->setEnabled(true);
        ui->pushButtonVisualiserVoiture->setEnabled(true);
        ui->pushButtonNouveauContrat->setEnabled(true);
        ui->pushButtonSupprimerContrat->setEnabled(true);
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Table des options du projet en cours (ne pas modifier) /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setTableOption(int indice,string code,string intitule,float prix)
{
    // Modifie l'option de la ligne correspondant à l'indice fourni dans la table des options de l'interface graphique
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(code.c_str());
    ui->tableWidgetOptions->setItem(indice,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    char tmp[20];
    sprintf(tmp,"%.2f",prix);
    if (prix < 0.0) item->setText("");
    else item->setText(tmp);
    ui->tableWidgetOptions->setItem(indice,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(intitule.c_str());
    ui->tableWidgetOptions->setItem(indice,2,item);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::videTableOption()
{
    for (int i=0 ; i<5 ; i++) setTableOption(i);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndiceOptionSelectionneeTable() const
{
    // retourne l'indice de l'option selectionnee dans la table des options
    QModelIndexList liste = ui->tableWidgetOptions->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Combobox des modèles disponibles (ne pas modifier) /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::ajouteModeleDisponible(const char* nom,float prixDeBase)
{
    // ajoute un modèle dans le combobox correspondant (juste le nom et le prix)
    stringstream ss;
    char temp[20];
    sprintf(temp,"%.2f",prixDeBase);
    ss << nom << " (" << temp << ")";
    ui->comboBoxModelesDisponibles->addItem(ss.str().c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::videComboboxModelesDisponibles()
{
    ui->comboBoxModelesDisponibles->clear();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndiceModeleSelectionneCombobox() const
{
    // retourne l'indice du modèle selectionné dans le combobox des modèles
    return ui->comboBoxModelesDisponibles->currentIndex();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Combox des options disponibles (ne pas modifier) ///////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::ajouteOptionDisponible(string intitule,float prix)
{
    // ajoute une option dans le combobox correspondant
    stringstream ss;
    char temp[20];
    sprintf(temp,"%.2f",prix);
    ss << intitule << " (" << temp << ")";
    ui->comboBoxOptionsDisponibles->addItem(ss.str().c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::videComboboxOptionsDisponibles()
{
    ui->comboBoxOptionsDisponibles->clear();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndiceOptionSelectionneeCombobox() const
{
    // retourne l'indice de l'option selectionnée dans le combobox des options
    return ui->comboBoxOptionsDisponibles->currentIndex();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Gestion du Projet en cours (ne pas modifier) ///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setNomProjetEnCours(string nom)
{
    // Remplit le champ nom de l'interface graphique avec le nom reçu
    ui->lineEditNomProjet->setText(nom.c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicGarageWindow::getNomProjetEnCours() const
{
    return ui->lineEditNomProjet->text().toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setModele(string nom,int puissance,int moteur,float prixDeBase,string imageModele)
{
    // Remplit les champs correspondants dans l'interface graphique
    // pour le moteur (int) : 0=Essence, 1=Diesel, 2=Electrique, 3=Hybride
    ui->lineEditNomModele->setText(nom.c_str());
    ui->lineEditPuissance->setText(to_string(puissance).c_str());
    char tmp[20];
    sprintf(tmp,"%.2f",prixDeBase);
    ui->lineEditPrixDeBase->setText(tmp);

    ui->radioButtonEssence->setChecked(false);
    ui->radioButtonDiesel->setChecked(false);
    ui->radioButtonElectrique->setChecked(false);
    ui->radioButtonHybride->setChecked(false);

    if (moteur == 0) ui->radioButtonEssence->setChecked(true);
    if (moteur == 1) ui->radioButtonDiesel->setChecked(true);
    if (moteur == 2) ui->radioButtonElectrique->setChecked(true);
    if (moteur == 3) ui->radioButtonHybride->setChecked(true);

    // Met à jour l'image du modèle
    string cheminComplet = REPERTOIRE_IMAGES + imageModele;
    QLabel* label = new QLabel();
    label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    label->setScaledContents(true);
    QPixmap *pixmap_img = new QPixmap(cheminComplet.c_str());
    label->setPixmap(*pixmap_img);
    label->resize(label->pixmap()->size());
    ui->scrollArea->setWidget(label);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setPrix(float prix)
{
  char tmp[20];
  sprintf(tmp,"%.2f",prix);
  ui->lineEditPrix->setText(tmp);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des Employes (ne pas modifier) //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::ajouteTupleTableEmployes(string tuple)
{
    // Controle du tuple recu et parsing
    char Tuple[200];
    strncpy(Tuple,tuple.c_str(),199);
    char* tmp;

    if ((tmp = strtok(Tuple,";")) == NULL) return;
    char numero[20];
    strcpy(numero,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char nom[40];
    strcpy(nom,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char prenom[40];
    strcpy(prenom,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char fonction[40];
    strcpy(fonction,tmp);

    // Ajout possible
    int nbLignes = ui->tableWidgetEmployes->rowCount();
    nbLignes++;
    ui->tableWidgetEmployes->setRowCount(nbLignes);
    ui->tableWidgetEmployes->setRowHeight(nbLignes-1,10);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(numero);
    ui->tableWidgetEmployes->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(nom);
    ui->tableWidgetEmployes->setItem(nbLignes-1,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(prenom);
    ui->tableWidgetEmployes->setItem(nbLignes-1,2,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(fonction);
    ui->tableWidgetEmployes->setItem(nbLignes-1,3,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::videTableEmployes()
{
    ui->tableWidgetEmployes->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndiceEmployeSelectionne()
{
    QModelIndexList liste = ui->tableWidgetEmployes->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des Clients (ne pas modifier) ///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::ajouteTupleTableClients(string tuple)
{
    // Controle du tuple recu et parsing
    char Tuple[200];
    strncpy(Tuple,tuple.c_str(),199);
    char* tmp;

    if ((tmp = strtok(Tuple,";")) == NULL) return;
    char numero[20];
    strcpy(numero,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char nom[40];
    strcpy(nom,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char prenom[40];
    strcpy(prenom,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char gsm[40];
    strcpy(gsm,tmp);

    // Ajout possible
    int nbLignes = ui->tableWidgetClients->rowCount();
    nbLignes++;
    ui->tableWidgetClients->setRowCount(nbLignes);
    ui->tableWidgetClients->setRowHeight(nbLignes-1,10);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(numero);
    ui->tableWidgetClients->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(nom);
    ui->tableWidgetClients->setItem(nbLignes-1,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(prenom);
    ui->tableWidgetClients->setItem(nbLignes-1,2,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(gsm);
    ui->tableWidgetClients->setItem(nbLignes-1,3,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::videTableClients()
{
    ui->tableWidgetClients->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndiceClientSelectionne()
{
    QModelIndexList liste = ui->tableWidgetClients->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des Contrats (ne pas modifier) //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::ajouteTupleTableContrats(string tuple)
{
    // Controle du tuple recu et parsing
    char Tuple[200];
    strncpy(Tuple,tuple.c_str(),199);
    char* tmp;

    if ((tmp = strtok(Tuple,";")) == NULL) return;
    char numero[20];
    strcpy(numero,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char vendeur[40];
    strcpy(vendeur,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char client[40];
    strcpy(client,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char voiture[40];
    strcpy(voiture,tmp);

    // Ajout possible
    int nbLignes = ui->tableWidgetContrats->rowCount();
    nbLignes++;
    ui->tableWidgetContrats->setRowCount(nbLignes);
    ui->tableWidgetContrats->setRowHeight(nbLignes-1,10);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(numero);
    ui->tableWidgetContrats->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(vendeur);
    ui->tableWidgetContrats->setItem(nbLignes-1,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(client);
    ui->tableWidgetContrats->setItem(nbLignes-1,2,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(voiture);
    ui->tableWidgetContrats->setItem(nbLignes-1,3,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::videTableContrats()
{
    ui->tableWidgetContrats->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndiceContratSelectionne()
{
    QModelIndexList liste = ui->tableWidgetContrats->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions permettant d'afficher des boites de dialogue /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::dialogueMessage(const char* titre,const char* message)
{
   QMessageBox::information(this,titre,message);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::dialogueErreur(const char* titre,const char* message)
{
   QMessageBox::critical(this,titre,message);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicGarageWindow::dialogueDemandeTexte(const char* titre,const char* question)
{
    QString chaine = QInputDialog::getText(this,titre,question);
    return chaine.toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::dialogueDemandeInt(const char* titre,const char* question)
{
    return QInputDialog::getInt(this,titre,question);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
float ApplicGarageWindow::dialogueDemandeFloat(const char* titre,const char* question)
{
    return QInputDialog::getDouble(this,titre,question);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les items de menu //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionQuitter_triggered()
{
  // TO DO (étape 12)

  QApplication::exit();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::closeEvent(QCloseEvent *event)
{
  if (event == NULL) {}  // pour éviter le warning
  // TO DO (étape 12)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionNouveau_modele_triggered()
{
  // Saisie des informations (aucune vérification n'est faite --> à gérer si vous voulez)
  char tmp[100];
  string nomModele = dialogueDemandeTexte("Nouveau modèle","Nom :");
  int puissance = dialogueDemandeInt("Nouveau modèle","Puissance :");
  int moteur = dialogueDemandeInt("Nouveau modèle :","Moteur (0=essence,1=diesel,2=électrique,3=hybride) :");
  float prixDeBase = dialogueDemandeFloat("Nouveau modèle","Prix de base :");
  string image = dialogueDemandeTexte("Nouveau modèle","Nom du fichier de l'image :");

  // TO DO (étape 9)

  strcpy(tmp, nomModele.data());
  Garage::getInstance().ajouteModele(Modele(tmp, puissance,(Moteur)moteur, prixDeBase, image));

  ajouteModeleDisponible(tmp, prixDeBase);

 

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionNouvelle_option_triggered()
{

    // Saisie des informations (aucune vérification n'est faite --> à gérer si vous voulez)
    string code = dialogueDemandeTexte("Nouvelle option","Code :");
    string intitule = dialogueDemandeTexte("Nouvelle option","Intitule :");
    float prix = dialogueDemandeFloat("Nouvelle option","Prix :");

    // TO DO (étape 9)
    try
    {
        Garage::getInstance().ajouteOption(Option(code, intitule, prix));
        ajouteOptionDisponible(intitule, prix);    
    }
    catch(OptionException& e)
    {
        dialogueErreur("Erreur d'options", e.getMessage().data());
    }

   

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionAjouterEmploye_triggered()
{
    // TO DO (étape 11)
    int i;
    string fonction;
    string nom = dialogueDemandeTexte("Nouveau Employé","Nom :");
    string prenom = dialogueDemandeTexte("Nouveau Employé","Prenom :");
    string login = dialogueDemandeTexte("Nouveau Employé","Login :");
    int fonctionI = dialogueDemandeInt("Nouveau Employé","Fonction (0 = administratif, 1 = vendeur) : ");

    if (fonctionI == 0)
    {
        fonction = "Administratif";
    }
    else
    {
        fonction = "Vendeur";
    }

    Garage::getInstance().ajouteEmploye(nom, prenom, login, fonction);
    //ajouteOptionDisponible(intitule, prix);
    videTableEmployes();
    for (i=0; i < Garage::getInstance().getSizeEmploye(); i++)
    {
        ajouteTupleTableEmployes(Garage::getInstance().getEmploye(i).Tuple());
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionSupprimerEmploye_par_numero_triggered()
{
    // TO DO (étape 11)
    int i;
    int num = dialogueDemandeInt("Supprimer par numéro","Numéro : "); // 

    Garage::getInstance().supprimeEmployeParNumero(num);

    videTableEmployes();
    for (i=0; i < Garage::getInstance().getSizeEmploye(); i++)
    {
        ajouteTupleTableEmployes(Garage::getInstance().getEmploye(i).Tuple());
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionSupprimerEmploye_selection_triggered()
{
    // TO DO (étape 11)
    int i;
    int num = getIndiceEmployeSelectionne();
    if (num !=-1)
    {
        Garage::getInstance().supprimeEmployeParNumero(Garage::getInstance().getEmploye(num).getNumero());


        videTableEmployes();
        for (i=0; i < Garage::getInstance().getSizeEmploye(); i++)
        {
            ajouteTupleTableEmployes(Garage::getInstance().getEmploye(i).Tuple());
        }
    }
    else
    {
        dialogueErreur("Erreur de suppression", "Aucun employé n’est sélectionné");
    }



    

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionAjouterClient_triggered()
{
    // TO DO (étape 11)
    int i;
    string nom = dialogueDemandeTexte("Nouveau Employé","Nom :");
    string prenom = dialogueDemandeTexte("Nouveau Employé","Prenom :");
    string gsm = dialogueDemandeTexte("Nouveau Employé","GSM :");

    Garage::getInstance().ajouteClient(nom, prenom, gsm);
    videTableClients();
    for (i=0; i < Garage::getInstance().getSizeClient(); i++)
    {
        ajouteTupleTableClients(Garage::getInstance().getClient(i).Tuple());
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionSupprimerClient_par_numero_triggered()
{
  // TO DO (étape 11)
    int i;
    int num = dialogueDemandeInt("Supprimer par numéro","Numéro : "); // 

    Garage::getInstance().supprimeClientParNumero(num);
    
    videTableClients();
    for (i=0; i < Garage::getInstance().getSizeClient(); i++)
    {
        ajouteTupleTableClients(Garage::getInstance().getClient(i).Tuple());
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionSupprimerClient_selection_triggered()
{
    // TO DO (étape 11)
    int i;
    int num = getIndiceClientSelectionne();
    if (num !=-1)
    {
        Garage::getInstance().supprimeClientParNumero(Garage::getInstance().getClient(num).getNumero());
        videTableClients();
        for (i=0; i < Garage::getInstance().getSizeClient(); i++)
        {
            ajouteTupleTableClients(Garage::getInstance().getClient(i).Tuple());
        }
    }
    else
    {
        dialogueErreur("Erreur de suppression", "Aucun employé n’est sélectionné");
    }



    

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionLogin_triggered()
{
    // TO DO (étape 11)
    int i;
    string titre;

    string login = dialogueDemandeTexte("Connexion","Login :");

    for (i=0; i < Garage::getInstance().getSizeEmploye(); i++)
    {
        if (Garage::getInstance().getEmploye(i).getLogin() == login)
        {
            Garage::getInstance().employe = Garage::getInstance().getEmployePt(i);
            try
            {
                Garage::getInstance().getEmploye(i).getMotDePasse();

                string mdp = dialogueDemandeTexte("Connexion","Mot de passe :");
                if (Garage::getInstance().getEmploye(i).getMotDePasse() == mdp)
                {
                    if (Garage::getInstance().getEmploye(i).getFonction() == "Administratif")
                    {
                        setRole(1);
                        titre = "Application Garage : " + Garage::getInstance().employe->getNom() + " " + Garage::getInstance().employe->getPrenom() + " (Administratif)";
                        setTitre(titre);
                    }
                    else
                    {
                        titre = "Application Garage : " + Garage::getInstance().employe->getNom() + " " + Garage::getInstance().employe->getPrenom() + " (Vendeur)";
                        setTitre(titre);
                        setRole(2);

                    }
                    dialogueMessage("Connexion réussie", "Vous êtes bien connecté");
                }
                else
                {
                    dialogueErreur("Erreur de connexion", "Mot de passe incorrect !");
                }
            }
            catch(PasswordException& e)
            {
                dialogueMessage("Première connexion", "Vous n’avez pas de mot de passe, vous allez devoir en encoder un");
                string mdp = dialogueDemandeTexte("Nouveau employé !","Enrégistrez votre mot de passe :");
                try
                {
                    Garage::getInstance().employe->setMotDePasse(mdp);
                    dialogueMessage("Mot de passe enregistré", "Vous avez bien été enregistrez !");
                }
                catch(PasswordException& e)
                {
                    dialogueErreur("Erreur de mot de passe", e.getMessage().data());
                }
                
            }
            return;
        }
    }
    dialogueErreur("Erreur de Connexion", "Login non trouvé !");


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionLogout_triggered()
{
    // TO DO (étape 11)
    setRole(0);
    setTitre("Application Garage");
    Garage::getInstance().employe = NULL;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionReset_Mot_de_passe_triggered()
{
    // TO DO (étape 11)
    Garage::getInstance().employe->resetMotDePasse();
    dialogueMessage("Mot de passe réinitialisé", "Votre mot de passe à été réinitialisé");

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonChoisirModele_clicked()
{
    // TO DO (étape 9)
    Voiture voiture;
    int ind = getIndiceModeleSelectionneCombobox();
    if (ind != -1)
    {
        Garage::getProjetEnCours().setModele(Garage::getInstance().getModele(ind));
        voiture = Garage::getProjetEnCours();
        setModele(voiture.getModele().getNom(),voiture.getModele().getPuissance(),voiture.getModele().getMoteur(),voiture.getModele().getPrixDeBase(),voiture.getModele().getImage());
        cout << "DEBUG : " << voiture.getModele().getImage() << endl;
        setPrix(voiture.getPrix());
    }   
    else
    {
        dialogueErreur("Erreur", "Aucun véhicule sélectioné");
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonAjouterOption_clicked()
{
    // TO DO (étape 9)
    Option * opt;
    int ind = getIndiceOptionSelectionneeCombobox();
    if (ind != -1)
    {
        try
        {
            Garage::getProjetEnCours().AjouteOption(Garage::getInstance().getOption(ind));
            for(int i=0;i<5;i++)
            {
                opt = Garage::getProjetEnCours()[i];
                if (opt != NULL)
                {
                    setTableOption(i, Garage::getProjetEnCours()[i]->getCode(), Garage::getProjetEnCours()[i]->getIntitule(), Garage::getProjetEnCours()[i]->getPrix());
                }
                else
                {
                    setTableOption(i);
                }
                
            }
            setPrix(Garage::getProjetEnCours().getPrix());
        }
        catch(OptionException& e)
        {
            dialogueErreur("Erreur d'options", e.getMessage().data());
        }
        
        
    }   
    else
    {
        dialogueErreur("Erreur", "Aucune option sélectioné");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonSupprimerOption_clicked()
{
    // TO DO (étape 9)
    Option * opt;
    int ind = getIndiceOptionSelectionneeTable();
    if (ind != -1)
    {
        opt = Garage::getProjetEnCours()[ind];
        if (opt != NULL)
        {
            Garage::getProjetEnCours().RetireOption(opt->getCode());
            setTableOption(ind);
            setPrix(Garage::getProjetEnCours().getPrix());
        }
        else
        {
            dialogueErreur("Erreur de suppression", "L'option sélectioné n'existe pas");
        }
        
    }   
    else
    {
        dialogueErreur("Erreur de suppression", "Aucune option sélectioné");
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonReduction_clicked()
{
    // TO DO (étape 9)
    Option * opt;
    int ind = getIndiceOptionSelectionneeTable();
    if (ind != -1)
    {
        opt = Garage::getProjetEnCours()[ind];
        if (opt != NULL)
        {
            try
            {
                (*opt)--;
                setTableOption(ind, Garage::getProjetEnCours()[ind]->getCode(), Garage::getProjetEnCours()[ind]->getIntitule(), Garage::getProjetEnCours()[ind]->getPrix());
                setPrix(Garage::getProjetEnCours().getPrix());
            }
            catch(OptionException& e)
            {
                dialogueErreur("Erreur de réduction", e.getMessage().data());
            }
        }
        else
        {
            dialogueErreur("Erreur de suppression", "L'option sélectioné n'existe pas");
        }
        
    }   
    else
    {
        dialogueErreur("Erreur de suppression", "Aucune option sélectioné");
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonEnregistrerProjet_clicked()
{
    // TO DO (étape 9)
    Garage::getProjetEnCours().setNom(getNomProjetEnCours());
    Garage::getProjetEnCours().Save();

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonOuvrirProjet_clicked()
{
    // TO DO (étape 9)
    Voiture voiture;
    Option * opt;
    Garage::getProjetEnCours().Load(getNomProjetEnCours()); // charger le projet

    for(int i=0;i<5;i++) // boucle pour afficher les opts
    {
        opt = Garage::getProjetEnCours()[i];
        if (opt != NULL)
        {
            setTableOption(i, Garage::getProjetEnCours()[i]->getCode(), Garage::getProjetEnCours()[i]->getIntitule(), Garage::getProjetEnCours()[i]->getPrix());
        }
        else
        {
            setTableOption(i);
        }
        
    }
    setPrix(Garage::getProjetEnCours().getPrix());
    
    voiture = Garage::getProjetEnCours();
    setModele(voiture.getModele().getNom(),voiture.getModele().getPuissance(),voiture.getModele().getMoteur(),voiture.getModele().getPrixDeBase(),voiture.getModele().getImage());
        

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonNouveauProjet_clicked()
{
    // TO DO (étape 9)
    Garage::resetProjetEnCours();
    for(int i=0;i<5;i++) // boucle pour supr m'affichage des opts
    {
        setTableOption(i);
    }
    setModele("",0,0,0,"");
    setPrix(0);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonNouveauContrat_clicked()
{
  // TO DO (étape 13)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonSupprimerContrat_clicked()
{
  // TO DO (étape 13)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonVisualiserVoiture_clicked()
{
  // TO DO (étape 13)

}


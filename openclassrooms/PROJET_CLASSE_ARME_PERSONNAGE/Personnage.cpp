#include "Personnage.hpp"

using namespace std;

Personnage::Personnage() : m_nom("David"), m_vie(100), m_mana(100)
{

}

Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100), m_arme(nomArme, degatsArme)
{
    cout << "Entrez le nom de votre personnage : " << endl;
    cin >> m_nom;
    cout << endl;
}

Personnage::~Personnage()
{

}

void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;

    if (m_vie < 0)
    {
        m_vie = 0;
    }
    cout << m_nom << " reçoit " << nbDegats << endl;
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme.getDegats());
    cout << m_nom << " attaque " << cible.m_nom << endl;
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100)
    {
        m_vie = 100;
    }
    cout << m_nom << " boit une potion et récupère " << quantitePotion << " points de vie" << endl;
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    cout << m_nom << " change d'arme pour " << m_arme.getName() << endl;
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant()
{
    if (m_vie > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Personnage::afficherEtat()
{
    cout << "Nom : " << m_nom << endl;
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme.afficher();
}

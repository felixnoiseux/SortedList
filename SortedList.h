#ifndef  SORTEDLIST _H__
#define SORTEDLIST_H__
//Felix Noiseux 26 Fevrier 2019
template <class T>
class SortedList
{
public:
	~SortedList();
	void Ajouter(const T& element);
	void AfficherCroissant() const;
	void AfficherDecroissant() const;
	bool Contient(const T& element) const;
	int Count() const;
private:
	struct Noeud
	{
		T valeur;
		Noeud* suivant;
		Noeud* precedent;
	};
	int m_count = 0;
	Noeud* m_debut = 0;
	Noeud* racine = 0;
	Noeud* fin = 0;
	void Vider();
	void CroissantRecursif(Noeud* Suivant) const;
	void DecroissantRecursif(Noeud* Precedent) const;
};

template<class T>
SortedList<T>::~SortedList()
{
	Vider();
}

template<class T>
void SortedList<T>::Ajouter(const T & element)
{
	Noeud *n = new Noeud();
	n->valeur = element;

	while (n)
	{
		if (m_debut == nullptr)
		{
			m_debut = n;
			racine = n;
			break;
		}
		if (m_debut->valeur == element)
		{
			m_count--;
			break;
		}
		if (n->valeur > m_debut->valeur && m_debut->suivant == nullptr)
		{
			n->precedent = m_debut;
			m_debut->suivant = n;
			fin = n;
			break;
		}
		else if (n->valeur < m_debut->suivant->valeur && n->valeur > m_debut->valeur)
		{
			n->suivant = m_debut->suivant;
			n->precedent = m_debut;

			m_debut->suivant->precedent = n;
			m_debut->suivant = n;
			break;
		}
		else
		{
			if (n->valeur > m_debut->valeur)
				m_debut = m_debut->suivant;
			else
			{
				if (m_debut->precedent == NULL)
				{
					n->suivant = m_debut;
					m_debut->precedent = n;	
					racine = n;
				}
				else
					m_debut = m_debut->precedent;
			}
		}
	}
	m_count++;
}

template<class T>
void SortedList<T>::AfficherCroissant() const
{
	CroissantRecursif(racine);
}

template<class T>
void SortedList<T>::AfficherDecroissant() const
{
	DecroissantRecursif(fin);
}

template<class T>
bool SortedList<T>::Contient(const T & element) const
{
	Noeud* n = m_debut;
	while (n)
	{
		if (n->valeur != element)
		{
			if (n->suivant != nullptr)
				n = n->suivant;
			else
				return false;
		}
		else
			return true;
	}
	return false;
}

template<class T>
int SortedList<T>::Count() const
{
	return m_count;
}

template<class T>
void SortedList<T>::Vider()
{
	Noeud * n = racine;
	while (n)
	{
		Noeud* Suivant = n->suivant;
		delete n;
		n = Suivant;
	}
	m_debut = 0;
	racine = 0;
}

template<class T>
void SortedList<T>::CroissantRecursif(Noeud* Suivant) const
{
	std::cout << Suivant->valeur << std::endl;

	if (Suivant->suivant != NULL)
		CroissantRecursif(Suivant->suivant);
}

template<class T>
void SortedList<T>::DecroissantRecursif(Noeud * Precedent) const
{
	std::cout << Precedent->valeur << std::endl;

	if (Precedent->precedent != NULL)
		DecroissantRecursif(Precedent->precedent);
}
#endif // ! SORTEDLIST _H__
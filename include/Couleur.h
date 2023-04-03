
class Couleur
{
private:
    /* data */
    int r;
    int g;
    int b;
    int alpha;
public:
    Couleur();
    Couleur(int r, int g, int b, int alpha);
    Couleur interpoler(const Couleur &c, float t) const;
    const int& operator const;
    int& operator;
    /// @brief 
    /// @param c 
    /// @return 
    bool operator==(const Couleur &c) const;
    
};


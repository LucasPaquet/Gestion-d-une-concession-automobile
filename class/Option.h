#ifndef OPTION_H
#define OPTION_H

class Option
{
private:
  std::string code;
  std::string intitule;
  float prix;

public:
  //constructeur
  Option();
  Option(std::string code, std::string intitule, float prix);
  Option(const Option& p);
  //destructeur
  ~Option();
  // getteur
  std::string getCode() const ;
  std::string getIntitule() const ;
  float getPrix() const;
  //setteur
  void setCode(std::string s);
  void setIntitule(std::string s);
  void setPrix(float p);
  //fonctions
  void Affiche();
};

#endif
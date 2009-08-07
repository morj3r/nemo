// ============================================================================
// Copyright Jean-Charles LAMBERT - 2007-2009                                  
// e-mail:   Jean-Charles.Lambert@oamp.fr                                      
// address:  Dynamique des galaxies                                            
//           Laboratoire d'Astrophysique de Marseille                          
//           P�le de l'Etoile, site de Ch�teau-Gombert                         
//           38, rue Fr�d�ric Joliot-Curie                                     
//           13388 Marseille cedex 13 France                                   
//           CNRS U.M.R 6110                                                   
// ============================================================================
// See the complete license in LICENSE and/or "http://www.cecill.info".        
// ============================================================================
/**
	@author Jean-Charles Lambert <Jean-Charles.Lambert@oamp.fr>
*/
#ifndef GLNEMOGLOBJECT_H
#define GLNEMOGLOBJECT_H

#include <QGLWidget>
#include <QObject>
namespace glnemo {


class GLObject : public QObject {
Q_OBJECT
public:
  GLObject();

  ~GLObject();
  GLObject(const GLObject& m):QObject() {

    is_activated = m.is_activated;
    mycolor      = m.mycolor;
    width        = m.width;
    height       = m.height;
    dplist_index = m.dplist_index;
    particles_alpha = m.particles_alpha;
  };
  const GLObject & operator=(const GLObject & m) {
    is_activated = m.is_activated;
    mycolor      = m.mycolor;
    width        = m.width;
    height       = m.height;
    dplist_index = m.dplist_index;
    particles_alpha = m.particles_alpha;
    return *this;
  }
// method
  void display(int my_list=-1);
  void setColor(const QColor&);
  void toggleActivate();
  bool getActivate() { return is_activated; };
  void setActivate(bool status) { is_activated = status ;}; 
  void setWH(int new_w, int new_h) { width=new_w; height=new_h; };
// protected slots:
  void updateAlphaSlot(const int);
  
 protected:
  bool is_activated;    // 
  QColor mycolor;
  GLuint dplist_index;
  int width,height;              // Display width and height
  int particles_alpha;  
  // method
  void  buildDisplayList();

};

}

#endif
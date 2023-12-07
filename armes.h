#ifndef ARMES_H_INCLUDED
#define ARMES_H_INCLUDED

class armes{
public:
    virtual ~armes()=default;
    virtual void utiliser() const =0;
    virtual void recupererPoint() const =0;

};

#endif // ARMES_H_INCLUDED

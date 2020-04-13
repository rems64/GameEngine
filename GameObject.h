#ifndef DEF_GAMEOBJECT
#define DEF_GAMEOBJECT


class GameObject
{
  public:
    GameObject();
    virtual void draw();
    void setVisibility(bool);
    void toggleVisibility();
    bool isVisible();
    bool m_isVisible;
    GameObject *m_parent;
};

#endif

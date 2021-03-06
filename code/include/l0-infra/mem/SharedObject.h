#ifndef H38247538_297F_4A80_94D3_8A28978846FA
#define H38247538_297F_4A80_94D3_8A28978846FA


struct SharedObject
{
    SharedObject();
    virtual ~SharedObject();
    
    void addRef();
    void subRef();
    void setOnlyFree();
    virtual void destroy(){};
    virtual bool needDestroy(){return false;};

    unsigned int getRefCount() const;

    bool onlyThisRef() const;

private:
    unsigned int count;
};



#endif

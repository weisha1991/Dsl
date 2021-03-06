#ifndef H38247538_297F_4A80_94D3_8F28978846FA
#define H38247538_297F_4A80_94D3_8F28978846FA


#include <string.h>



template <typename OBJ>
struct StructObject : OBJ
{
	StructObject()
	{
		reset();
	}

	void reset()
	{
		::memset((void*)this, 0x00, sizeof(OBJ));
	}

	OBJ& operator*()
    {
        return *this;
    }

    const OBJ& operator*() const
    {
        return *this;
    }

    OBJ* operator->()
    {
        return this;
    }

    const OBJ* operator->() const
    {
        return this;
    }

    OBJ* getPointer()
    {
        return this;
    }

    const OBJ* getPointer() const
    {
        return this;
    }
};



#endif


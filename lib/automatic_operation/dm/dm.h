#ifndef __DM_H__
#define __DM_H__

#include <ActiveQt/QAxWidget>

class DM
{

public:
    DM();
    ~DM();
    QAxWidget * dm_handle;

private:
    void reg_dm(void);
    void dm_handle_init(void);
};

#endif // __DM_H__

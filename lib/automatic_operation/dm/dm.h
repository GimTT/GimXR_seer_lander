#ifndef __DM_H__
#define __DM_H__

#include <ActiveQt/QAxWidget>

class DM
{

public:
    DM();
    ~DM();
    void bind_window(uint64_t pid);

private:
    QAxWidget * dm_handle;
    void reg(void);
    void handle_init(void);
};

#endif // __DM_H__

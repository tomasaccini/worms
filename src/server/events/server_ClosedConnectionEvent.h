#ifndef __CLOSEDCONNECTIONEVENT__
#define __CLOSEDCONNECTIONEVENT__

#include "server_IEvent.h"
#include <stdexcept>

// Hereda de IEvent. Cierra la conexión.
class ClosedConnectionEvent : public IEvent {
private:
    ClosedConnectionEvent(const ClosedConnectionEvent&) = delete;
    ClosedConnectionEvent& operator=(const ClosedConnectionEvent&) = delete;
public:
    ClosedConnectionEvent();

    void run();

    ~ClosedConnectionEvent() = default;
};


#endif //__CLOSEDCONNECTIONEVENT__

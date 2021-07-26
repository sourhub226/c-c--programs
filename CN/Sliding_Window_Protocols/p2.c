/* Protocol 2 (stop-and-wait) also provides for 
   - a one-directional flow of data from sender to receiver. 
   - The communication channel is once again assumed to be error free, 
     as in protocol 1. 
   - However, this time, the receiver has only a finite buffer
     capacity and a finite procesing speed, so the protocol must 
     explicitly prevent the sender from flooding the receiver 
     with data faster than it can be handled. 
    
   The solution is to use acknowledgement frames.

*/

typedef enum {frame_arrival} event_type;

#include "protocol.h"

void
sender2(void)
{
  packet buffer;     /* buffer for an outbound packet */
  frame s;           /* buffer for an outbound frame */
  event_type event;  /* frame_arrival (ACK) is the only possibility */

  while (true)
  {
    from_network_layer(&buffer); /* go get something to send */
    s.info = buffer;             /* copy it into s for transmission */
    to_physical_layer(&s);       /* send off the frame */
    wait_for_event(&event);      /* do not proceed until an ACK received */
  }
}

void
receiver2(void)
{
  frame r, s;        /* buffers for frames */
  event_type event;  /* frame_arrival is the only possibility */
  while (true)
  {
    wait_for_event(&event);    /* only possibility is frame_arrival */
    from_physical_layer(&r);   /* go get the inbound frame */
    to_network_layer(&r.info); /* pass the data to the network layer */
    to_physical_layer(&s);     /* send a dummy frame (ACK) to awaken sender */
  }
}
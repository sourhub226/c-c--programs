/* Protocol (stop-and-wait ARQ Automatic Repeat Request) provides for
   - a one-directional flow of data from sender to receiver.
   - The communication channel is unreliable (errors, packet loss).
   - Also, the receiver has only a finite buffer
     capacity and a finite procesing speed, so the protocol must
     explicitly prevent the sender from flooding the receiver
     with data faster than it can be handled.
*/

#define MAX_SEQ 1  /* must be 1 for protocol 3, modulo 1 inc() */

typedef enum {frame_arrival, cksum_err, timeout} event_type;

#include "protocol.h"

void
sender3(void)
{
  packet buffer;             /* buffer for an outbound packet */
  frame s;                   /* buffer for frames */
  seq_nr next_frame_to_send; /* seq number of next outgoing frame */
  event_type event;

  next_frame_to_send = 0;       /* initialize outbound sequence numbers */
  from_network_layer(&buffer);  /* fetch first packet */
  while (true)
  {
    s.info = buffer;            /* construct a frame for transmission */
    s.seq = next_frame_to_send; /* insert sequence number in frame */
    to_physical_layer(&s);      /* send it on its way */
    start_timer(s.seq);         /* if answer takes too long, time out */
    wait_for_event(&event);     /* frame_arrival, cksum_err, timeout */
    if (event == frame_arrival)
    {
      from_physical_layer(&s);  /* get the acknowledgement */
      if (s.ack == next_frame_to_send)
      {
        from_network_layer(&buffer); /* get the next one to send */
        inc(next_frame_to_send);     /* invert next_frame_to_send */
      }
      /* else if (s.ack != next_frame_to_send) re-send */
    }
    /* else if (event == timeout) re-send */
  }
}

void
receiver3(void)
{
  seq_nr frame_expected; /* seq number of next frame expected */
  frame r, s;            /* buffer for frames */
  event_type event;

  frame_expected = 0;
  while (true)
  {
    wait_for_event(&event); /* possibilities: frame_arrival, cksum_err */

    if (event == frame_arrival) /* A valid frame has arrived. */
    {
      from_physical_layer(&r);    /* go get the newly arrived valid frame */

      if (r.seq == frame_expected)
      {
        /* This is what we have been waiting for. */
        to_network_layer(&r.info); /* pass the data to the network layer */
        inc(frame_expected);       /* next time expect the other sequence nr */
      }
      /* else if (r.seq != frame_expected) ignore */

      s.ack = 1 - frame_expected; /* tell which frame is being acked */
      to_physical_layer(&s);      /* only the ack field is use, no data */
    }
    /* else if (event == cksum_err) treat as non-arrival */
  }
}
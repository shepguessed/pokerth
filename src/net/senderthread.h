/***************************************************************************
 *   Copyright (C) 2007 by Lothar May                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
/* Network sender thread. */

#ifndef _SENDERTHREAD_H_
#define _SENDERTHREAD_H_

#include <core/thread.h>
#include <net/socket_helper.h>

#include <deque>
#include <boost/shared_ptr.hpp>

class ClientData;
class NetPacket;

class SenderThread : public Thread
{
public:
	SenderThread();
	virtual ~SenderThread();

	// Set the socket from which to receive data.
	// TODO: Add error callback.
	void Init(SOCKET socket);

	void Send(boost::shared_ptr<NetPacket> packet);

protected:

	// Main function of the thread.
	virtual void Main();

private:

	SOCKET m_socket;

	std::deque<boost::shared_ptr<NetPacket> > m_outBuf;
	mutable boost::mutex m_outBufMutex;
};

#endif


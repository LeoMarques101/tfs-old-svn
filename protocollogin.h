//////////////////////////////////////////////////////////////////////
// OpenTibia - an opensource roleplaying game
//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////

#ifndef __OTSERV_PROTOCOL_LOGIN_H__
#define __OTSERV_PROTOCOL_LOGIN_H__
#include "protocol.h"

class NetworkMessage;
class OutputMessage;

class ProtocolLogin : public Protocol
{
	public:
#ifdef __ENABLE_SERVER_DIAGNOSTIC__
		static uint32_t protocolLoginCount;
#endif
		ProtocolLogin(Connection* connection) : Protocol(connection)
		{
#ifdef __ENABLE_SERVER_DIAGNOSTIC__
			protocolLoginCount++;
#endif
		}
		virtual ~ProtocolLogin()
		{
#ifdef __ENABLE_SERVER_DIAGNOSTIC__
			protocolLoginCount--;
#endif
		}

		enum {protocolId = 0x01};
		enum {isSingleSocket = false};
		enum {hasChecksum = true};

		virtual void onRecvFirstMessage(NetworkMessage& msg) {parseFirstPacket(msg);}

	protected:
		void disconnectClient(uint8_t error, const char* message);
		bool parseFirstPacket(NetworkMessage& msg);
		virtual void deleteProtocolTask();
};

#endif

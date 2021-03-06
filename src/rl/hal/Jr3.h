//
// Copyright (c) 2009, Markus Rickert
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//

#ifndef _RL_HAL_JR3_H_
#define _RL_HAL_JR3_H_

#include <string>

#include "SixAxisForceTorqueSensor.h"

namespace rl
{
	namespace hal
	{
		class Comedi;
		
		class Jr3 : public SixAxisForceTorqueSensor
		{
		public:
			Jr3(const ::std::string& filename = "/dev/comedi0");
			
			virtual ~Jr3();
			
			void bias();
			
			void close();
			
			void getForces(::rl::math::Vector& forces) const;
			
			::rl::math::Real getForcesMaximum(const ::std::size_t& i) const;
			
			::rl::math::Real getForcesMinimum(const ::std::size_t& i) const;
			
			void getForcesTorques(::rl::math::Vector& forcesTorques) const;
			
			::rl::math::Real getForcesTorquesMaximum(const ::std::size_t& i) const;
			
			::rl::math::Real getForcesTorquesMinimum(const ::std::size_t& i) const;
			
			void getTorques(::rl::math::Vector& torques) const;
			
			::rl::math::Real getTorquesMaximum(const ::std::size_t& i) const;
			
			::rl::math::Real getTorquesMinimum(const ::std::size_t& i) const;
			
			void open();
			
			void resetBias();
			
			void start();
			
			void step();
			
			void stop();
			
		protected:
			
		private:
			Comedi* comedi;
			
			float values[6];
			
			float zeroes[6];
		};
	}
}

#endif // _RL_HAL_JR3_H_

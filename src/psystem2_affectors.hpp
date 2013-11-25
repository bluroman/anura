/*
	Copyright (C) 2003-2013 by Kristina Simpson <sweet.kristas@gmail.com>
	
	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	   1. The origin of this software must not be misrepresented; you must not
	   claim that you wrote the original software. If you use this software
	   in a product, an acknowledgment in the product documentation would be
	   appreciated but is not required.

	   2. Altered source versions must be plainly marked as such, and must not be
	   misrepresented as being the original software.

	   3. This notice may not be removed or altered from any source
	   distribution.
*/

#pragma once

#include "psystem2_fwd.hpp"

namespace graphics
{
	namespace particles
	{
		class affector
		{
		public:
			explicit affector(const variant& node, technique* tech);
			virtual ~affector();

			bool enabled() const { return enabled_; }
			void enable(bool en) { enabled_ = en; }

			static affector_ptr factory(const variant& node, technique* tech);
			void apply(std::vector<particle>& particles, std::vector<emitter_ptr>& emitters, float t);
		protected:
			float mass() const { return mass_; }
			const glm::vec3& position() const { return position_; }
			virtual void handle_apply(std::vector<particle>& particles, float t) = 0;
			virtual void handle_apply(std::vector<emitter_ptr>& emitters, float t) = 0;
			bool is_emitter_excluded(const std::string& name);
			technique* get_technique() { return technique_; }
		private:
			bool enabled_;
			float mass_;
			glm::vec3 position_;
			std::vector<std::string> excluded_emitters_;
			technique* technique_;
			affector();
			affector(const affector&);
		};
	}
}
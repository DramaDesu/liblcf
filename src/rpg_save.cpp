/////////////////////////////////////////////////////////////////////////////
// This file is part of EasyRPG.
//
// EasyRPG is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// EasyRPG is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "rpg_save.h"
#include "data.h"

////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////
RPG::Save::Save() {
	unknown_70 = -1;
}

void RPG::Save::Setup() {
	system.Setup();
	pictures.resize(50);
	actors.resize(Data::actors.size());
	for (int i = 1; i <= (int) actors.size(); i++)
		actors[i - 1].Setup(i);
	map_info.Setup();
}

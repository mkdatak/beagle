/*
 *  Open BEAGLE
 *  Copyright (C) 2001-2007 by Christian Gagne and Marc Parizeau
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Contact:
 *  Laboratoire de Vision et Systemes Numeriques
 *  Departement de genie electrique et de genie informatique
 *  Universite Laval, Quebec, Canada, G1K 7P4
 *  http://vision.gel.ulaval.ca
 *
 */

/*!
 *  \file   Beagle/Core/IsEqualMapPairPredicate.hpp
 *  \brief  Definition of class IsEqualMapPairPredicate.
 *  \author Christian Gagne
 *  \author Marc Parizeau
 *  $Revision: 1.8 $
 *  $Date: 2007/08/08 19:26:44 $
 */

#ifndef Beagle_Core_IsEqualMapPairPredicate_hpp
#define Beagle_Core_IsEqualMapPairPredicate_hpp

#include <utility>
#include <string>

#include "Beagle/config.hpp"
#include "Beagle/macros.hpp"
#include "Beagle/Core/Object.hpp"
#include "Beagle/Core/Pointer.hpp"

namespace Beagle
{


/*!
 *  \class IsEqualMapPairPredicate Beagle/Core/IsEqualMapPairPredicate.hpp
 *    "Beagle/Core/IsEqualMapPairPredicate.hpp"
 *  \brief Binary predicate functor that test if two std::pair<string,Object::Handle> are
 *    equals.
 *  \ingroup Core
 *  \ingroup Utils
 *  \par Note:
 *    The IsEqualMapPairPredicate is compliant with the STL BinaryPredicate functor.
 *    See http://www.sgi.com/tech/stl/BinaryPredicate.html
 */
class IsEqualMapPairPredicate
{

public:
	IsEqualMapPairPredicate()
	{ }
	~IsEqualMapPairPredicate()
	{ }

	/*!
	 *  \brief Test if the pairs are equal.
	 *  \param inLeftPair Left map pair object to compare.
	 *  \param inRightPair Right map pair to compare.
	 */
	inline bool operator()(const std::pair<std::string,Object::Handle>& inLeftPair,
	                       const std::pair<std::string,Object::Handle>& inRightPair) const
	{
		Beagle_StackTraceBeginM();
		if(inLeftPair.first != inRightPair.first) return false;
		if( (!inLeftPair.second) && (!inRightPair.second) ) return true;
		else if( (!inLeftPair.second) || (!inRightPair.second) ) return false;
		return inLeftPair.second->isEqual(*inRightPair.second);
		Beagle_StackTraceEndM("bool operator()(const std::pair<std::string,Object::Handle>& inLeftPair, const std::pair<std::string,Object::Handle>& inRightPair) const");
	}

};

}

#endif // Beagle_Core_IsEqualMapPairPredicate_hpp

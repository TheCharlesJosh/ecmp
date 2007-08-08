/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2006 INRIA
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Mathieu Lacage <mathieu.lacage@sophia.inria.fr>
 */
#ifndef TAG_H
#define TAG_H

/**
 * \relates Tag
 * \brief this macro should be instantiated exactly once for each
 *        new type of Tag
 *
 * This macro will ensure that your new Tag type is registered
 * within the tag registry. In most cases, this macro
 * is not really needed but, for safety, please, use it all the
 * time.
 *
 * Note: This macro is _absolutely_ needed if you try to run a
 * distributed simulation.
 */
#define NS_TAG_ENSURE_REGISTERED(x)	       \
static class thisisaveryverylongclassname ##x  \
{					       \
 public:				       \
  thisisaveryverylongclassname ##x ()          \
    { uint32_t uid; uid = x::GetUid ();}       \
} g_thisisanotherveryveryverylongname ## x;

namespace ns3 {

class Tag
{
protected:
  template <typename T>
  static uint32_t AllocateUid (std::string name);
};

} // namespace ns3

// implementation below.
#include "tag-registry.h"

namespace ns3 {

template <typename T>
uint32_t
Tag::AllocateUid (std::string name)
{
  return TagRegistry::Register<T> (name);
}

} // namespace ns3

#endif /* TAG_H */

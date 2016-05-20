/*
 * p4-validation-model: Reference model for P4 programs in the PFPSim Framework
 *
 * Copyright (C) 2016 Concordia Univ., Montreal
 *     Samar Abdi
 *     Umair Aftab
 *     Gordon Bailey
 *     Faras Dewal
 *     Shafigh Parsazad
 *     Eric Tremblay
 *
 * Copyright (C) 2016 Ericsson
 *     Bochra Boughzala
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef READ_WRITE_LOCK_H_
#define READ_WRITE_LOCK_H_

#include "systemc"
#include <set>

class ReadWriteLock {
 public:
  ReadWriteLock();

  ReadWriteLock(const ReadWriteLock &) = delete;
  ReadWriteLock & operator=(const ReadWriteLock &) = delete;

  void read_lock();
  void read_unlock();

  void write_lock();
  void write_unlock();

 private:
  std::set<sc_core::sc_process_b*> readers;
  sc_core::sc_process_b* writer;

  sc_core::sc_event cond;
};

#endif

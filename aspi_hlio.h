/*
 * aspi_hlio.h - ASPI high-level I/O
 * $Id: aspi_hlio.h,v 1.2 2004/08/15 16:44:19 b081 Exp $
 *
 * Copyright 2004 Bobi B., w1zard0f07@yahoo.com
 *
 * This file is part of hdl_dump.
 *
 * hdl_dump is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * hdl_dump is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with hdl_dump; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#if !defined (_ASPI_HLIO_H)
#define _ASPI_HLIO_H

#include <stddef.h>


typedef struct scsi_device_type scsi_device_t;
typedef struct scsi_devices_list_type scsi_devices_list_t;

struct scsi_device_type
{
  int host, scsi_id, lun;
  int type; /* 0: probably a HDD; 5: MMC device (CD- or DVD-drive) */
  size_t align;
  char name [28 + 1];
};

struct scsi_devices_list_type
{
  size_t used, alloc;
  scsi_device_t *device;
};


int aspi_load (void);
int aspi_unload (void);

int aspi_scan_scsi_bus (scsi_devices_list_t **list);
void aspi_dlist_free (scsi_devices_list_t *list);

int aspi_stat (int host,
	       int scsi_id,
	       int lun,
	       size_t *size_in_sectors,
	       size_t *sector_size);

int aspi_mmc_read_cd (int host,
		      int scsi_id,
		      int lun,
		      size_t start_sector,
		      size_t num_sectors,
		      size_t sector_size,
		      void *output);

int aspi_read_10 (int host,
		  int scsi_id,
		  int lun,
		  size_t start_sector,
		  size_t num_sectors,
		  void *output);


#endif /* _ASPI_HLIO_H defined? */

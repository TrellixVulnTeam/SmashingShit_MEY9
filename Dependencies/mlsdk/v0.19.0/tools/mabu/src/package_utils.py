# %BANNER_BEGIN%
# ---------------------------------------------------------------------
# %COPYRIGHT_BEGIN%
#
# Copyright (c) 2018 Magic Leap, Inc. (COMPANY) All Rights Reserved.
# Magic Leap, Inc. Confidential and Proprietary
#
#  NOTICE:  All information contained herein is, and remains the property
#  of COMPANY. The intellectual and technical concepts contained herein
#  are proprietary to COMPANY and may be covered by U.S. and Foreign
#  Patents, patents in process, and are protected by trade secret or
#  copyright law.  Dissemination of this information or reproduction of
#  this material is strictly forbidden unless prior written permission is
#  obtained from COMPANY.  Access to the source code contained herein is
#  hereby forbidden to anyone except current COMPANY employees, managers
#  or contractors who have executed Confidentiality and Non-disclosure
#  agreements explicitly covering such access.
#
#  The copyright notice above does not evidence any actual or intended
#  publication or disclosure  of  this source code, which includes
#  information that is confidential and/or proprietary, and is a trade
#  secret, of  COMPANY.   ANY REPRODUCTION, MODIFICATION, DISTRIBUTION,
#  PUBLIC  PERFORMANCE, OR PUBLIC DISPLAY OF OR THROUGH USE  OF THIS
#  SOURCE CODE  WITHOUT THE EXPRESS WRITTEN CONSENT OF COMPANY IS
#  STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE LAWS AND
#  INTERNATIONAL TREATIES.  THE RECEIPT OR POSSESSION OF  THIS SOURCE
#  CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS
#  TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE,
#  USE, OR SELL ANYTHING THAT IT  MAY DESCRIBE, IN WHOLE OR IN PART.
#
# %COPYRIGHT_END%
# ---------------------------------------------------------------------
# %BANNER_END%
import os

import diags
import taildata_v3
from build_model import BuildException
from config import SIGN_CERT, SIGN_PRIVKEY
# noinspection PyUnresolvedReferences
from taildata import taildata_module, find_tail_data  #  (exported for clients)


def is_elf(file):
    # check the first 4 bytes of the file for the ELF magic number - 0x7F(454c46) - ELF
    try:
        with open(file, 'rb') as fileobj:
            return fileobj.read(4) == b'\x7fELF'
    except IOError:
        pass
    return False


def is_secure_file(file):
    """
    Tell whether this file needs security bits
    :param file: path
    :type file: str
    :return: bool
    """
    # ignore .sym files that may be bundled
    if file.endswith('.sym'):
        return False

    # only modify elf files
    if not is_elf(file):
        return False
    return True


def is_linked(path):
    try:
        st = os.stat(path)
        return st.st_nlink > 1
    except OSError:
        return False

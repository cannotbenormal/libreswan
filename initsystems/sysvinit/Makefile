ifndef top_srcdir
include ../../mk/dirs.mk
endif

LIBRESWANSRCDIR?=$(shell cd ../..; pwd)
SRCDIR?=${LIBRESWANSRCDIR}/initsystems/sysvinit/

INITDFILE=$(builddir)/ipsec.init
SYSCONFIGFILE=$(builddir)/sysconfig.pluto
SUBDIRS=
SYSCONFIGDIR=$(SYSCONFDIR)/sysconfig
SYSVINIT_DEFAULT_START?=

include $(top_srcdir)/mk/config.mk

# Use dependencies to force the order.
#
# (Without this, since local-install-base depends local-base, rules
# like local-base and installinitfiles and checkenabled are allowed to
# run in parallel)

local-base:     $(INITDFILE) $(SYSCONFIGFILE)
local-install-base: installinitfiles installsysconfig checkenabled

installinitfiles: local-base
	mkdir -p $(INITDDIR)
	$(INSTALL) $(INITDFILE) $(INITDDIR)/ipsec

installsysconfig: local-base
	mkdir -p $(SYSCONFIGDIR)
	if test ! -f $(SYSCONFIGDIR)/pluto ; then \
		$(INSTALL) $(INSTCONFFLAGS) $(SYSCONFIGFILE) $(SYSCONFIGDIR)/pluto ; \
	fi

checkenabled: installinitfiles installsysconfig
	@count=0 ; \
	for dir in $(DESTDIR)/etc/rc?.d ; do \
		if test -f $$dir/S??ipsec.init ; then \
			count=1 ; \
		fi ; \
	done ; \
	if test $$count = 0 ; then \
		echo "************************** WARNING ***********************************" ; \
		echo "** The ipsec service is not enabled." ; \
		echo "** Enable it using 'chkconfig ipsec on' or another similar method." ; \
		echo "**********************************************************************" ; \
	fi

include ${top_srcdir}/mk/targets.mk
include ${top_srcdir}/mk/rules.mk

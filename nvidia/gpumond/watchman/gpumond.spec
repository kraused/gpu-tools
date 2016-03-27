
# We follow the Fedora naming scheme:
# https://fedoraproject.org/wiki/Packaging:NamingGuidelines?rd=Packaging/NamingGuidelines#NonNumericRelease
%define checkout	20160327git19fc1ce

Name:		gpumond
Version:	1.0
Release:	1.%{checkout}%{?dist}
Summary:	GPU monitoring daemon
Group:		System Environment/Base
License:	GPLv2

Source:		%{name}-%{version}-%{checkout}.tar.gz

Requires:	watchman xorg-x11-drv-nvidia-libs
BuildRequires:	watchman-devel gpu-deployment-kit

%description
This package provides the gpumond GPU monitoring daemon.

%prep
%setup -q -n %{name}-%{version}-%{checkout}

%build
make 
make -C watchman

%install
make PREFIX=%{buildroot} install
make PREFIX=%{buildroot} -C watchman install

%files
%defattr(-,root,root)
%dir %attr(0755,root,root)
%dir /usr/libexec/gpumond
/usr/sbin/gpumond.exe
/usr/libexec/gpumond/gpumond-watchman.so
/usr/lib/systemd/system/gpumond.service


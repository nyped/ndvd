# Maintainer: lennypeers <lennypeers+git at gmail>
pkgname=ndvd
pkgver=0.1
pkgrel=3
pkgdesc="the famous dvd animation"
arch=(x86_64)
url="https://github.com/lennypeers/ndvd"
license=(AGPL)
depends=(ncurses)
makedepends=(git gcc)
source=("git+https://github.com/lennypeers/ndvd.git")
md5sums=('SKIP')

package() {
	cd "$srcdir/$pkgname"
	make DESTDIR="$pkgdir/" install
}

/*--------------------------------------------------------------------------

	Copyright © 2021, Yoshiki Tanaka
	
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*///------------------------------------------------------------------------

#include <progress_bar.hpp>
#include <ui_progress_bar.h>

#include <QWidget>

ProgressBar::ProgressBar(QWidget *parent)
:	QWidget(parent), 
    ui_(new Ui::progress_bar_ui),
    denominator_(0),
    nominator_(0)
{
    this->ui_->setupUi(this);
}

ProgressBar::~ProgressBar()
{
    delete this->ui_;
}

void ProgressBar::add_line(const QString& str)
{
    this->ui_->plainTextEdit->appendPlainText(str);
}

void ProgressBar::clear_text()
{
    this->ui_->plainTextEdit->clear();
}

void ProgressBar::inc_denominator()
{
    this->denominator_++;
}

void ProgressBar::inc_nominator()
{
    this->nominator_++;
    this->calc_pasent();
}

void ProgressBar::clear_counter()
{
    this->denominator_ = 0;
    this->nominator_ = 0;
    this->ui_->progressBar->setValue(0);
}

void ProgressBar::calc_pasent()
{
    auto result = this->nominator_ / static_cast<long double>(this->denominator_);
    result *= 100.;
    this->ui_->progressBar->setValue(result);
}

void ProgressBar::clear_all()
{
    this->clear_text();
    this->clear_counter();
}

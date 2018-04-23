/* 
	ComboBox Object 
	http://www.zoonman.com/projects/combobox/

	Copyright (c) 2011, Tkachev Philipp
	All rights reserved.
	BSD License
	
*/
ComboBox = function(object_name) {
  // Edit element cache
  this.edit = document.getElementById(object_name);
  // Items Container
  var ddl = document.getElementById(object_name)
      .parentNode
      .getElementsByTagName('DIV');
  this.dropdownlist = ddl[0];
  // Current Item
  this.currentitem = null;
  // Current Item Index
  this.currentitemindex = null;
  // Visible Items Count
  this.visiblecount = 0;
  // Closure Object
  var parobject = this;
  // Picker
  var pick = document.getElementById(object_name)
      .parentNode
      .getElementsByTagName('SPAN');
  pick[0].onclick = function() {
    parobject.edit.focus();
  };
  // Show Items when edit get focus
  this.edit.onfocus = function() {
    parobject.dropdownlist.style.display = 'block';
  };
  // Hide Items when edit lost focus
  this.edit.onblur = function() {
    if (allowLoose) {
      setTimeout(function() {
            parobject.dropdownlist.style.display = 'none';
          },
          150
      );
    }
  };
  var allowLoose = true;
  // IE fix
  parobject.dropdownlist.onmousedown = function(event) {
    allowLoose = false;
    return false;
  };
  parobject.dropdownlist.onmouseup = function(event) {
    setTimeout(function() {
      allowLoose = true;
    }, 150);
    return false;
  };
  // Get Items
  this.listitems = this.dropdownlist.getElementsByTagName('A');
  for (var i = 0; i < this.listitems.length; i++) {
    var t = i;
    // Binding Click Event
    this.listitems[i].onclick = function() {
      var upv = this.innerHTML;
      upv = upv.replace(/\<b\>/ig, '');
      upv = upv.replace(/\<\/b\>/ig, '');
      parobject.edit.value = upv;
      parobject.dropdownlist.style.display = 'none';
      return false;
    };
    // Binding OnMouseOver Event
    this.listitems[i].onmouseover = function(e) {
      for (var i = 0; i < parobject.listitems.length; i++) {
        if (this === parobject.listitems[i]) {
          if (parobject.currentitem) {
            parobject.currentitem.className = parobject.currentitem.className.replace(
                /light/g,
                ''
            );
          }
          parobject.currentitem = parobject.listitems[i];
          parobject.currentitemindex = i;
          parobject.currentitem.className += ' light';
        }
      }
    }
  }
  // Binding OnKeyDown Event
  this.edit.onkeydown = function(e) {
    e = e || window.event;
    // Move Selection Up
    if (e.keyCode === 38) {
      // up
      var cn = 0;
      if (parobject.visiblecount > 0) {
        if (parobject.visiblecount === 1) {
          parobject.currentitemindex = parobject.listitems.length - 1;
        }
        do {
          parobject.currentitemindex--;
          cn++;
        }
        while (parobject.currentitemindex > 0 && parobject.listitems[parobject.currentitemindex].style.display === 'none');
        if (parobject.currentitemindex < 0){
          parobject.currentitemindex = parobject.listitems.length - 1;
        }

        if (parobject.currentitem) {
          parobject.currentitem.className = parobject.currentitem.className.replace(
              /light/g,
              ''
          )
        }
        parobject.currentitem = parobject.listitems[parobject.currentitemindex];
        parobject.currentitem.className += ' light';
        parobject.currentitem.scrollIntoView(false);
      }
      e.cancelBubble = true;
      if (navigator.appName !== 'Microsoft Internet Explorer') {
        e.preventDefault();
        e.stopPropagation();
      }
      return false;
    }
    // Move Selection Down
    else if (e.keyCode === 40) {
      // down
      var ic = 0;
      if (parobject.visiblecount > 0) {
        do {
          parobject.currentitemindex++;
        }
        while (parobject.currentitemindex < parobject.listitems.length && parobject.listitems[parobject.currentitemindex].style.display === 'none');
        if (parobject.currentitemindex >= parobject.listitems.length){parobject.currentitemindex = 0;
}

        if (parobject.currentitem) {
          parobject.currentitem.className = parobject.currentitem.className.replace(
              /light/g,
              ''
          )
        }
        parobject.currentitem = parobject.listitems[parobject.currentitemindex];
        parobject.currentitem.className += ' light';
        parobject.currentitem.scrollIntoView(false);
      }
      e.cancelBubble = true;
      if (navigator.appName != 'Microsoft Internet Explorer') {
        e.preventDefault();
        e.stopPropagation();
      }
      return false;
    }

  };
  this.edit.onkeyup = function(e) {
    e = e || window.event;
    if (e.keyCode === 13) {
      // enter
      if (parobject.visiblecount != 0) {
        var upv = parobject.currentitem.innerHTML;
        upv = upv.replace(/\<b\>/ig, '');
        upv = upv.replace(/\<\/b\>/ig, '');
        parobject.edit.value = upv;
      }
      parobject.dropdownlist.style.display = 'none';
      e.cancelBubble = true;
      return false;
    }
    else {
      parobject.dropdownlist.style.display = 'block';
      parobject.visiblecount = 0;
      if (parobject.edit.value === '') {
        for (var i = 0; i < parobject.listitems.length; i++) {
          parobject.listitems[i].style.display = 'block';
          parobject.visiblecount++;
          var pv = parobject.listitems[i].innerHTML;
          pv = pv.replace(/\<b\>/ig, '');
          parobject.listitems[i].innerHTML = pv.replace(/\<\/b\>/ig, '');
        }
      }
      else {
        var re = new RegExp('(' + parobject.edit.value + ')', "i");
        for (var i = 0; i < parobject.listitems.length; i++) {
          var pv = parobject.listitems[i].innerHTML;
          pv = pv.replace(/\<b\>/ig, '');
          pv = pv.replace(/\<\/b\>/ig, '');
          if (re.test(pv)) {
            parobject.listitems[i].style.display = 'block';
            parobject.visiblecount++;
            parobject.listitems[i].innerHTML = pv.replace(re, '<b>$1</b>');
          }
          else {
            parobject.listitems[i].style.display = 'none';
          }
        }
      }
    }
  }
};

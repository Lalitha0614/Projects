 // Function to show the sidebar
 function showSidebar() {
    const sidebar = document.querySelector('.sidebar');
    sidebar.style.display = 'flex';
  }

  // Function to hide the sidebar
  function hideSidebar() {
    const sidebar = document.querySelector('.sidebar');
    sidebar.style.display = 'none';
  }

  // Add event listener to window object to detect scrolling
  window.addEventListener('scroll', function() {
    // Call hideSidebar() function to hide the sidebar when scrolling occurs
    hideSidebar();
  });

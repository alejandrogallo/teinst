(require 'ob-shell)
(setq org-confirm-babel-evaluate nil)

(defun header (msg)
  (message "\n\n» %s\n\n" msg))

(header "FIRST TANGLE")
(org-babel-tangle)

(header "EXECUTE BUFFER TO INSTANTIATE")
(org-babel-execute-buffer)

(header "LAST TANGLE")
(org-babel-tangle)

(message "\n\nSAVING BUFFER\n\n")
(save-buffer)

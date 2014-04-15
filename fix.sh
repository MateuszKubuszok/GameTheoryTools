git filter-branch --commit-filter '
        if [ "$GIT_COMMITTER_NAME" = "Remigiusz Wawrzyniak" ];
        then
                GIT_COMMITTER_NAME="Mateusz Kubuszok";
                GIT_AUTHOR_NAME="Mateusz Kubuszok";
                GIT_COMMITTER_EMAIL="mateusz.kubuszok@gmail.com";
                GIT_AUTHOR_EMAIL="mateusz.kubuszok@gmail.com";
                git commit-tree "$@";
        else
                git commit-tree "$@";
        fi' HEAD